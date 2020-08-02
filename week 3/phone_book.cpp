#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    string found="not found";
    vector<string> result;
    vector<string> check(10000000);
    for(size_t i=0;i<queries.size();i++)
    {
        if(queries[i].type=="add")
        {
           check[queries[i].number]=queries[i].name;

        }
        else
            {if(queries[i].type=="del")
            {
               check[queries[i].number]="";    
            }
            else
            {if(check[queries[i].number]!="")
               result.push_back(check[queries[i].number]);
                
                else
                result.push_back(found);   

      }    }  }
  
    


    return result;

}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
