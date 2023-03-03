#include <iostream>
using namespace std;
#define maxx 10000
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int val) : val(val), next(NULL) {}
};
/**
 * @brief 递归的思想
 * 将当前的值与后面部分的链表的最大值相比，得到最大值
 *
 * @param f
 * @return int
 */
int Max(ListNode *f)
{
	int max;
	if (f->next == NULL)
		a return f->val;
	else
	{
		max = Max(f->next);
		return f->val > max ? f->val : max;
	}
}
void show(ListNode *f)
{
	while (f)
	{
		cout << f->val << endl;
		f = f->next;
	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		int a[maxx + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		// 后插法创建链表
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		for (int i = 0; i < n; i++)
		{
			ListNode *p = new ListNode(a[i]);
			cur->next = p;
			cur = p;
		}
		// show(head->next);
		cout << Max(head->next) << endl;
	}
	return 0;
}
