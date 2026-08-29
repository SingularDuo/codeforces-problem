#include <cstdio>
#include <set>
using namespace std;
const int maxn = 210000;
int a[maxn], nt[maxn];
bool head[maxn];
struct node
{
	int x, inx;
	node(int x = 0, int inx = 0):x(x),inx(inx) {}
	bool operator < (const node &b)const
	{
		if (x != b.x)return x > b.x;
		return inx < b.inx;
	}
};
 
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	set<node> S;
	for (int i = 0; i < n; i++)
	{
		auto it = S.upper_bound(node(a[i], 0));
		if (it == S.end())
		{
			head[i] = true;
			S.insert(node(a[i], i));
		}
		else
		{
			node ele = *it;
			nt[ele.inx] = i;
			S.erase(it);
			S.insert(node(a[i], i));
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (head[i])
		{
			printf("%d", a[i]);
			int x = nt[i];
			while (x != 0)
			{
				printf(" %d", a[x]);
				x = nt[x];
			}
			printf("
");
		}
	}
} 