#include<string>
#include<vector>
#include<iostream>

vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
    std::vector<string> v;
    int net=start;
    for(int i=0;i<12;i++){
      if(net<needed[i]){
        v.push_back("No problem. :(");
        net = net+created[i];
      }else{
        v.push_back("No problem! :D");
        net = net +created[i]-needed[i];
      }
    }

return v;
}
