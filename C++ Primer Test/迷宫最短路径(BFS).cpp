#include <iostream>
#include <deque>
#include <time.h>
using namespace std;

//������С·����ʵ�ֺ�����ͨ��BFS��ʽ���������ĵ������ʹ��DFS�㷨����Ҫ����еĵ����յ��·�������ȡ��̵�

/*�Թ�Ѱ�������������㷨�����/������������㷨���Լ�A*�㷨*/
/*��Զ��ԣ�����������������ʺ��Թ����·��Ѱ���ģ�ͨ��һ��һ�ֵı������ҵ��ĵ�һ��·��Ҳ������̵�·��*/
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }

static struct Cell
{
	int x, y; Status status;  //xy������������
	ESWN incoming, outgoing;  //����ķ������ȥ�ķ���
	Cell *prev;				  //����BFSʱ����ǰ׺�����ڽ�ͼ�γɷ���
};

#define LABY_MAX 40
static Cell laby[LABY_MAX][LABY_MAX];
static int ncheck, nback, length;

static inline Cell *neighbor(Cell *cell) //�ƶ���̽�⣬���õ���ǰcell���ھӣ�����outgoingȷ������
{
	switch (cell->outgoing)
	{
	case EAST:return cell + LABY_MAX;
	case SOUTH:return cell + 1;
	case WEST:return cell - LABY_MAX;
	case NORTH:return cell - 1;
	default:exit(-1); //����������ĸ����򣬼�UNKNOWN��NO_WAY����ֱ���˳����switchѭ��
	}
}

static inline Cell* advance(Cell* cell)  //ʵ���Ե��ƶ�������cell��incoming�ƶ���ǰcell����Ӧ��cell
{
	Cell *next;
	switch (cell->outgoing)
	{
	case EAST:next = cell + LABY_MAX; next->incoming = WEST; next->x = cell->x + 1; break;  //����Ĳ�����˼�ǣ��ֽڵ�Ľ���Ϊ�������൱��ԭ�ڵ�ĳ��Ƕ�
	case SOUTH:next = cell + 1;		  next->incoming = NORTH; next->y = cell->y + 1; break;
	case WEST:next = cell - LABY_MAX; next->incoming = EAST; next->x = cell->x - 1; break;
	case NORTH:next = cell - 1;		  next->incoming = SOUTH; next->y = cell->y - 1; break;
	default: exit(-1);
	}
	return next;
}

//���ĳһ�Թ������Ϣ
static inline void printLabyCell(Cell* elem)
{
	printf("%d -> (%d, %d) -> %d\n",
		((Cell*)elem)->incoming,
		((Cell*)elem)->x,
		((Cell*)elem)->y,
		((Cell*)elem)->outgoing);
}

void inline shortest_path(Cell *c)  //�˺������ڸ��ݴ��ݵ��յ�goalCell�����ݣ�������·������
{
	cout << "shortest path is: " << endl;
	c->status = ROUTE;   //���з��Ƶ�·��ȫ����״̬��ΪROUTE��������ʾ·��
	printLabyCell(c);
	while (c->incoming)  //һֱ���Ƶ����·���ĳ�ʼ�㣬����㣬����incoming��=0��
	{
		length++;        //length��ʼѭ������
		auto in = c->incoming;
		c = c->prev;
		switch (in)		 //������һ��cell��incoming�������Ƴ���ǰcell��outgoing�����ȡ������
		{
		case EAST:  c->outgoing = WEST;   break;
		case SOUTH: c->outgoing = NORTH;   break;
		case WEST: c->outgoing = EAST;   break;
		case NORTH: c->outgoing = SOUTH;   break;
		default: exit(-1);
		}
		c->status = ROUTE;
		printLabyCell(c);
	}
	cout << "shortest path's long is " << length + 1 << endl;  //�����յ�����ѭ���������ģ����Դ˴���Ҫ��1
}

static bool bfs(Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t)
{
	if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) return false;  //���ȣ������յ�������ܷ��ʵ�
	deque<Cell*> bfs_path;   //����BFS�㷨�����������Ϊʹ�ö��нṹ
	s->incoming = UNKNOWN; s->status = ROUTE; bfs_path.push_back(s);  //�����Ľ������Ϊ�ޣ�Ȼ��״̬��Ϊ��·���ϣ���������
	do
	{
		Cell *c = bfs_path.front();
		bfs_path.pop_front();
		if (c == t)
		{
			t = c;    //���ﵽ�յ�ʱ������ʱ��c���ݸ�goalCell����Ϊ���д����������е�prevǰ׺
			return true;
		}
		while (NO_WAY != (c->outgoing = nextESWN(c->outgoing)))   //�˴���Ϊ������ǰcell�����з���һ��
		{
			if (AVAILABLE == neighbor(c)->status)  //ֻҪcell��һ��������ԣ��ͽ������
			{
				Cell* temp = advance(c);
				temp->outgoing = UNKNOWN; temp->status = ROUTE;
				temp->prev = c;					   //ÿ���ӵ�ǰcell��ȥ��cell������ԭcell��Ϊǰ׺���ɴ�ʵ�ֵ�ǰͼ�������ṹ��ʵ��
				bfs_path.push_back(temp);
				ncheck++;
			}
		}
		c->status = BACKTRACKED;  //����bfs����cell������BACKTRACKED״̬����ʾ���Ѿ���ɨ�����û�е����յ�
	} while (!bfs_path.empty());
	return false;
}

static int labySize;  //�˴�����dascpp�е˹�������Թ����ɳ���
static Cell* startCell;
static Cell* goalCell;
static void randLaby()
{ 
	labySize = LABY_MAX / 2 + rand() % (LABY_MAX / 2);  //����һ�����size���Թ�
	/*DSA*/printf("Using a laby of size %d ...\n", labySize);
	for (int i = 0; i < labySize; i++)
		for (int j = 0; j < labySize; j++)
		{
			laby[i][j].x = i;
			laby[i][j].y = j;
			laby[i][j].incoming =
				laby[i][j].outgoing = UNKNOWN;
			laby[i][j].status = WALL; //�߽��������ǽ
		}
	for (int i = 1; i < labySize - 1; i++)
		for (int j = 1; j < labySize - 1; j++)
			if (rand() % 4) laby[i][j].status = AVAILABLE; //75%�ĸ��Ϊ�տ��ã������Թ��Ѷ��ڴ������޸�
	startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	startCell->status = goalCell->status = AVAILABLE; //��ʼ���������
}

//����ͬ�����õ��ǵ˹����Թ���ʾ����
//��ʾ�Թ�
static void displayLaby()
{ //������������
	static char*   pattern[5][5] =
	{
		"��", "��", "��", "��", "��",
		"��", "  ", "��", "��", "��",
		"��", "��", "  ", "��", "��",
		"��", "��", "��", "  ", "��",
		"��", "��", "��", "��", "  "
	};
	//system("cls");
	printf("  ");
	for (int j = 0; j < labySize; j++)
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
	printf("\n");
	for (int j = 0; j < labySize; j++)
	{
		(j < 10) ? printf("%2X", j) : printf(" %c", 'A' - 10 + j);
		for (int i = 0; i < labySize; i++)
			if (goalCell == &laby[i][j])
				printf("��");
			else
				switch (laby[i][j].status)
				{
				case WALL:  printf("��");   break;
				case BACKTRACKED: printf("��");   break;
				case AVAILABLE: printf("  ");   break;
				default: printf("%s ", pattern[laby[i][j].outgoing][laby[i][j].incoming]);  break; 
				//��ʦ����Ĵ���%s����û�пո���Ҫ���ϣ���Ȼ�Թ����ҵ�
				}
		printf("\n");
	}
}

int main()
{
	srand(int(time(0)));  //����ϵͳʱ��ȷ��������ӣ���֤ÿ��ִ�ж���ͬ
	randLaby();			  //��������Թ�
	if (bfs(laby, startCell, goalCell))  //�жϵ�ǰ�Թ��ܷ������ߵ��յ㣬����еĻ����������
	{
		cout << "true" << endl;
		cout << "start: " << "(" << startCell->x << "," << startCell->y << ")"            //�����ǰ�Թ��������յ�
			<< "  " << "end: " << "(" << goalCell->x << "," << goalCell->y << ")" << endl;
		shortest_path(goalCell); //�����ǰ�Թ�����㵽�յ�����·���볤��
	}
	else
		cout << "false" << endl;
	displayLaby();			 //�����ͼ��չʾ���·������������
	cout << "check times: "<<ncheck << endl;  //��������
	return 0;
}