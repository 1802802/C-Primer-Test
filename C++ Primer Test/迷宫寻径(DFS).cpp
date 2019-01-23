#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

//�������ܵõ��ľ���ֻ���жϵ�ǰ���Թ��Ƿ��ܹ��ҵ���·������С·�����ڸ��ʲ��������ԭ����Ŀǰ��DFS����ʱ��û��ʵ��

/*�Թ�Ѱ�������������㷨�����/������������㷨���Լ�A*�㷨*/
/*��Զ��ԣ�����������������ʺ��Թ���ȥ·��Ѱ���ģ�ͨ��һ��һ������̽�ͻ��ݣ��ܺܿ��ҵ�һ����ȥ��·*/
typedef enum { AVAILABLE, ROUTE, BACKTRACKED, WALL } Status;
typedef enum { UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY } ESWN;
inline ESWN nextESWN(ESWN eswn) { return ESWN(eswn + 1); }

static struct Cell
{
	int x, y; Status status;  //xy������������
	ESWN incoming, outgoing;  //����ķ������ȥ�ķ���
	Cell *prev;
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

static bool labyrinth(Cell Laby[LABY_MAX][LABY_MAX], Cell *s, Cell *t)
{
	if ((AVAILABLE != s->status) || (AVAILABLE != t->status)) return false;  //���ȣ������յ�������ܷ��ʵ�
	stack<Cell*> path;  //ջ�д�ŵĶ���ָ��cell��Ԫ��ָ�룬��������ջ�Ĳ������̶���ָ�����������Ч����Ч��
	s->incoming = UNKNOWN; s->status = ROUTE; path.push(s);  //�����Ľ������Ϊ�ޣ�Ȼ��״̬��Ϊ��·���ϣ������ջ
	do
	{
		Cell *c = path.top();  //c��ָ��ջ��Ԫ�ص�ָ�룬���ڴ���ǰջ���Ľڵ�����
		if (c == t)
		{
			length = path.size();
			return true;  //�Թ��������������ҵ��յ�
		}
		while (NO_WAY > (c->outgoing = nextESWN(c->outgoing)))  //��c�ĳ������ΪnextESWNö���е��¸�Ԫ�أ�δ֪��������������·��
			if (AVAILABLE == neighbor(c)->status) break;		//����c�ĸ����ھӣ������������򣩣�һ���п��еľ���������Ȼ��ѭ��
																//ע�������ѭ����ֹ������Ҫô���ھӿ��߾�������Ҫô�����ߵ���NO_WAY��Ҳ������·���ߣ���������
																//ͬʱע�⣬������whileѭ��������֮���cell���˶δ���ʱ������nextESWN����һ�����򣬲������һ����������ѭ�������
																//�����и�������˼���뷨����Ȼ�ڼ�鷽����϶����鵽��incoming�ķ��򣬵���ǰ����Կ�����ֻҪ�߹���·������ROUTE�����Բ������
		if (NO_WAY <= c->outgoing)  //˵���ˣ�������·�����ˣ���ͬ������˼
		{
			c->status = BACKTRACKED;  //����ǰ�Ľڵ�c������Ӧ��ջ��Ԫ�ر��ΪBACKTRACKED�����Ѿ��߹�������̽ȫ��ʧ�ܻ��ݵĵ㣬������߯��˹�ı�־
			path.pop();  //ջ��Ԫ�س�ջ������cell c�����ϻ��Ǵ��ڵģ�û��ɾ������ʵ����ʵ�ֻ���
			nback++;
		}
		else
		{
			path.push(c = advance(c));   //��c����ǰ����̽���еķ����ƶ�֮�󣬽��ƶ����c��ջ����ʱ��C�Ѿ���һ���µ�cellָ���ˣ�û��ָ��֮ǰ��ջ��Ԫ����
			c->outgoing = UNKNOWN;  //�µ�c�ĳ������ȻΪδ֪
			c->status = ROUTE; //�µ�ջ��Ԫ�صı�־��ΪROUTE����ʾ����·����̽��
			ncheck++;
		}
	} while (!path.empty());  //ֱ���洢·����pathΪ��
	length = path.size();
	return false;  //���ѭ����û��ʵ��true�ķ��أ�������㵽�յ�û��·����ô����ֻ�ܷ���false��
}

/******************************************************************************************
*   ���ĳһ�Թ������Ϣ
******************************************************************************************/
static void printLabyCell(Cell* elem)
{
	printf("%d -> (%d, %d) -> %d\n",
		((Cell*)elem)->incoming,
		((Cell*)elem)->x,
		((Cell*)elem)->y,
		((Cell*)elem)->outgoing);
}

static int labySize;  //�˴�����dascpp�е˹�������Թ����ɳ���
static Cell* startCell;
static Cell* goalCell;
static void randLaby()
{
	labySize = LABY_MAX / 2 + rand() % (LABY_MAX / 2); //����һ�����size���Թ�
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
			if (rand() % 4) laby[i][j].status = AVAILABLE; //75%�ĸ��Ϊ�տ���
	startCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	goalCell = &laby[rand() % (labySize - 2) + 1][rand() % (labySize - 2) + 1];
	startCell->status = goalCell->status = AVAILABLE; //��ʼ���������
}

//����ͬ�����õ��ǵ˹����Թ���ʾ����
/******************************************************************************************
* ��ʾ�Թ�
******************************************************************************************/
static void displayLaby() { //������������
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

int main_dfs()
{
	srand(int(time(0)));  //����ϵͳʱ��ȷ��������ӣ���֤ÿ��ִ�ж���ͬ
	randLaby();
	if (labyrinth(laby, startCell, goalCell))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	displayLaby();
	cout << "start: " << "(" << startCell->x << "," << startCell->y << ")"
		<< "  " << "end: " << "(" << goalCell->x << "," << goalCell->y << ")" << endl;
	cout << "check times: " << ncheck << " back times: " << nback << endl;
	cout << "length of path is " << length << endl;
	return 0;
}