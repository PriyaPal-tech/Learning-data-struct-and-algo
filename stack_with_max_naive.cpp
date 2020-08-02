#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    vector<int> max;
    int maximum;
  public:

    void Push(int value) {
        if(max.empty()){
        max.push_back(value);
       maximum=value;}
        if(value>=maximum)
        { max.push_back(value); 

            maximum=value;}
         stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
     int n=stack.size();
     int t=stack[n-1];
     int m=max.size();
       
        if(max[m-1]==t)
        {
            max.pop_back();
        }
         stack.pop_back();
    }

    int Max() {
        assert(stack.size());
        int n=max.size();
       return max[n-1];
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}