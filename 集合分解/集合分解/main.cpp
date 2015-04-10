#include <iostream>

using namespace std;


int visited[30];
int data[100][100];
bool result;
int groupc;
int countdata[100];
int group_numth;



void dfs(int cpleted,int value,int v_left)
{
	for (int i = 0; i < countdata[group_numth];i++)
	{
		if (!visited[i])
		{
			if (data[group_numth][i]<v_left)
			{
				visited[i] =1;
				dfs(cpleted, value, v_left - data[group_numth][i]);
				visited[i] = 0;
			}
			else if (data[group_numth][i] == v_left)
			{
				if (cpleted == 5)
				{
					result = true;
					return;
				}
				else if (cpleted < 5)
				{
					visited[i] = 1;
					dfs(cpleted + 1, value, value);
					visited[i] = 0;
				}
				else
					return;
			}
			else
				return;		
		}
	}
	
}

bool fenjie()
{
	memset(visited, 0, sizeof(int)* 100);
	result = false;
	int sum = 0;
	int value;
	for (int i = 0; i < countdata[i];i++)
	{
		sum = sum + data[group_numth][i];
	}
	value = sum / 6;
	dfs(0,value, value);

	return result;


	
}

int main()
{

	cin >> groupc;
	

	for (int i = 0; i < groupc;i++)
	{
		cin >> countdata[i];
		for (int j = 0; j < countdata[i];j++)
		{
			cin >> data[i][j];
		}
	}

	for (int i = 0; i < groupc;i++)
	{
		group_numth = i;
		if (fenjie())
		{
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;
	}


	return 0;
}