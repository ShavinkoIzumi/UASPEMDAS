#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

float sum(vector<float> a)
{
	float s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += a[i];
	}
	return s;
}

float mean(vector<float> a)
{
	return sum(a) / a.size();
}

float sqsum(vector<float> a)
{
	float s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += pow(a[i], 2);
	}
	return s;
}

float stdev(vector<float> nums)
{
	float N = nums.size();
	return pow(sqsum(nums) / N - pow(sum(nums) / N, 2), 0.5);
}

vector<float> operator-(vector<float> a, float b)
{
	vector<float> retvect;
	for (int i = 0; i < a.size(); i++)
	{
		retvect.push_back(a[i] - b);
	}
	return retvect;
}

vector<float> operator*(vector<float> a, vector<float> b)
{
	vector<float> retvect;
	for (int i = 0; i < a.size() ; i++)
	{
		retvect.push_back(a[i] * b[i]);
	}
	return retvect;
}

float pearsoncoeff(vector<float> X, vector<float> Y)
{
	return sum((X - mean(X))*(Y - mean(Y))) / (X.size()*stdev(X)* stdev(Y));
}

int main() {
	
	int N;
	cout << "Masukkan DATA : ";
	cin >> N;
	vector<float> X(N);
	vector<float> Y(N);

	for (int i = 0; i < X.size() ; i++)
	{
		cout<<"Nilai Data ke-"<<i+1<<endl;
		cout << "Masukkan nilai Data x-" << i+1 << ": ";
		cin >> X[i];
		cout << "Masukkan nilai Data y-" << i+1 << ": ";
		cin >> Y[i];
	}

	cout << fixed << setprecision(3) << pearsoncoeff(X, Y) << endl;

	return 0;
}
