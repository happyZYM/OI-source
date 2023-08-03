#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<set>

using namespace std;

void matrix_to_num(int r, int c, int len, int dep, int dir, int num);
void num_to_matrix(int r, int c, int len, int dep);
void get_dir(int num);

const int MAXN = 64 + 10;

int matrix[MAXN][MAXN];    //用于存储输入输出矩阵 
set<int> black;			   //用于存储黑块数字序列 
int n, dirs[MAXN];			//dirs:用于存储一个数字代表的5进制的各位数字 

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	int kase = 0;cin >> n;
	while (n)
	{
		cout << "Image " << ++kase << endl;
		if (n > 0)             	//矩阵转数字 
		{
			getchar();
			black.clear();
			for (int i = 0; i < n; i++)	
			{
				for (int j = 0; j < n; j++)
				{
					char ch = getchar();
					matrix[i][j] = ch - '0';
				}
				getchar();
			}
			matrix_to_num(0, 0, n, 1, 0, 0);  
			int cnt = 0;
			for(set<int>::iterator it = black.begin() ; it != black.end();it++) //输出数字，注意格式 
			{
				if (cnt % 12 == 0 && cnt) cout << endl;
				if (cnt % 12 != 0) cout << " ";
				cout << *it; cnt++;
			}
			if (black.size() != 0) cout << endl;
			cout << "Total number of black nodes = " << black.size()<< endl;
		}
		else											//数字转矩阵 
		{
			n = -n;
			int num;
			memset(matrix, 0, sizeof(matrix));	//初始化矩阵 
			while (cin >> num && num != -1)				//将每个数字数字所代表的区域矩阵涂黑 （置1） 
			{
				get_dir(num);					//10进制转5进制 
				num_to_matrix(0, 0, n,1);		 
			}
			for (int i = 0; i < n; i++)		//输出输出矩阵,需要注意格式 
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j]==1) cout << "*";
					else cout << ".";
				}
				cout << endl;
			}
		}
		cin >> n;
		if(n) cout << endl;				//每个输出结束之后有空行，最后一个输出不需要空行 
	}
	return 0;
}

void num_to_matrix(int r, int c, int len,int dep)  
{
	if(!dirs[dep])						//此时该子矩阵就是数字所表示的，进行涂黑处理 
	{
		for (int i = r; i < r + len; i++)
		{
			for (int j = c; j < c + len; j++)
			{
				matrix[i][j] = 1;
			}
		}
	}
	else							//对于每一层根据5进制代表的方位选择下一个子矩阵的位置 
	{
		switch (dirs[dep])
		{
		case 1:num_to_matrix(r, c, len / 2, dep + 1); break;
		case 2:num_to_matrix(r, c + len / 2, len / 2, dep + 1); break;
		case 3:num_to_matrix(r + len / 2, c, len / 2, dep + 1); break;
		case 4:num_to_matrix(r + len / 2, c + len / 2, len / 2, dep + 1); break;
		}
	}
}

void get_dir(int num)					//10进制转5进制，并将5进制的各位存入dirs中 
{
	memset(dirs, 0, sizeof(dirs));
	for (int i = 64; i > 0 ; i--)
	{
		int x = num / pow(5, i);
		if (x > 0)
		{
			dirs[i + 1] = x;
			num = num - x * pow(5, i);
		}
		
	}
	dirs[1] = num;
}

void matrix_to_num(int r, int c, int len, int dep,int dir,int num)
{
	int new_num = 0;
	bool hava_white = false, hava_black = false;		//是否含有黑块或者白块 
	for (int i = r; i < r+len; i++)
	{
		for (int j = c; j < c+len; j++)
		{
			if (matrix[i][j] == 0) hava_white = true;
			if (matrix[i][j] == 1) hava_black = true;
		}
		if (hava_white && hava_black) break;
	}
	if (dep > 1)								//计算该层所表示的5进制数字 
		new_num = pow(5, dep - 2)*dir + num;
	if (hava_white && hava_black)					//如果是灰色的（黑白快都有） ，继续对子矩阵进行DFS，直到找到纯色矩阵 
	{
		matrix_to_num(r, c, len / 2, dep + 1, 1, new_num);
		matrix_to_num(r, c + len / 2, len / 2, dep + 1, 2, new_num);
		matrix_to_num(r + len / 2, c, len / 2, dep + 1, 3, new_num);
		matrix_to_num(r + len / 2, c + len / 2, len / 2, dep + 1, 4, new_num);
	}
	else if (hava_black)
		black.insert(new_num);
	return;		 
}
