#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 定义二叉树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 大顶堆比较函数
struct Compare {
	bool operator()(const int &a, const int &b) {
		return a < b;
	}
};

// 构建大顶堆
void buildMaxHeap(priority_queue<int, vector<int>, Compare> &maxHeap, const vector<int> &nums) {
	for (int num : nums) {
		maxHeap.push(num);
	}
}

// 遍历二叉树，找出最大的20个数字
void findLargestNumbers(TreeNode *root, vector<int> &result, int k) {
	if (root == nullptr || k == 0) {
		return;
	}

	priority_queue<int, vector<int>, Compare> maxHeap;
	maxHeap.push(root->val);

	while (!maxHeap.empty() && k > 0) {
		int num = maxHeap.top();
		maxHeap.pop();
		result.push_back(num);
		k--;

		if (root->left != nullptr) {
			maxHeap.push(root->left->val);
		}

		if (root->right != nullptr) {
			maxHeap.push(root->right->val);
		}
	}
}

int main() {
	// 输入100万个随机数字
	vector<int> nums;
	for (int i = 0; i < 1000000; i++) {
		nums.push_back(rand() % 233333333);
	}
	cout << rand() % 233333333 << endl;
	cout << rand() % 233333333 << endl;
	cout << rand() % 233333333 << endl;
	// 构建二叉树
	TreeNode *root = new TreeNode(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		TreeNode *node = new TreeNode(nums[i]);
		TreeNode *curr = root;
		while (true) {
			if (nums[i] > curr->val) {
				if (curr->right == nullptr) {
					curr->right = node;
					break;
				} else {
					curr = curr->right;
				}
			} else {
				if (curr->left == nullptr) {
					curr->left = node;
					break;
				} else {
					curr = curr->left;
				}
			}
		}
	}

	// 找出最大的20个数字
	vector<int> result;
	findLargestNumbers(root, result, 20);

	// 输出结果
	cout << "最大的20个数字为：" << endl;
	for (int num : result) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}