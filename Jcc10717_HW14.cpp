
#include <iostream>
#include <vector>
using namespace std;

vector<int> divideAndConquer(vector <int> vecIn);
vector<int> combinedScan(vector <int> leftAnswer, vector <int> rightAnswer);
void printVector(vector <int> toPrint);

int main()
{ 
	vector <int> v = { 70,-1,-60,4,5,10,1,10 };

	cout << "Original Vector: " << endl;
	printVector(v);
	cout << endl;
	cout << endl;
	vector <int> answer;
	answer=divideAndConquer(v);
	cout << "min max"<<endl;
	printVector(answer);
	cout << endl;
	

}

vector<int> divideAndConquer(vector <int> vecIn) {
	int min;
	int max;

	int size = vecIn.size();

	vector <int> leftHalf;
	vector <int> rightHalf;
	vector <int> answer;

	int low = 0;
	int high = size;
	int mid = (low + (high-1)) / 2;
	
	
	//single case, the vector has 1 element, set it equal to min and max

	if (size==1) {
		//low and high are the same number in this case
		min = vecIn[0];
		max = vecIn[0];

		

		answer.push_back(min);
		answer.push_back(max);
		return answer;
	}
	else if (size==2) {
		
		min = vecIn[0];
		max = vecIn[0];
	
		if ((vecIn[1]) < min)
			min = vecIn[1];
		if ((vecIn[1]) > max)
			max = vecIn[1];

		answer.push_back(min);
		answer.push_back(max);
		return answer;

	}
	//recursion hypothesis:
	//When calling divideAndConquer on half a vector it will return a vector containing the min and max of that half
	else {//if larger than 2 elements in array
		
		vector <int> Leftanswer;
		vector <int> Rightanswer;

		//splitting the vector into 2 temps, one for each side
		for (int i = 0; i <= mid; i += 1) {
			leftHalf.push_back(vecIn[i]);
		}
		for (int i = mid+1; i < high; i += 1) {
			rightHalf.push_back(vecIn[i]);
		}
		//recursive calls for each side
		Leftanswer=divideAndConquer(leftHalf);
		Rightanswer=divideAndConquer(rightHalf);
		//now we need to scan the answer vector and make it only equal to the min and max
		answer=combinedScan(Leftanswer,Rightanswer);

		return answer;
	}
}

vector<int> combinedScan(vector <int> leftAnswer, vector <int> rightAnswer) {

	vector <int> combinedAnswer;
	
	int min = leftAnswer[0];
	int max = leftAnswer[0];
	
	if (leftAnswer[0] < rightAnswer[0]) {
		min = leftAnswer[0];
}
	else {
		min = rightAnswer[0];
	}

	if (leftAnswer[1] > rightAnswer[1]) {
		max = leftAnswer[1];
	}
	else {
		max = rightAnswer[1];
	}



	combinedAnswer.push_back(min);
	combinedAnswer.push_back(max);

	return combinedAnswer;
}

void printVector(vector <int> toPrint) {
	for (int i : toPrint) 
		cout << i<<" ";
}



