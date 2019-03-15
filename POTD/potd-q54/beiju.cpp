
#include <bits/stdc++.h>

using namespace std;


string beiju(string input) {

  string output;
  list<char> texto;
    list<char>::iterator it;
    texto.clear();
    it = texto.begin();
  for(int i=0;i<int(input.size());i++){
    if(input[i]=='[')
                   it = texto.begin();
               if(input[i]==']')
                   it = texto.end();
               if(input[i]!='[' && input[i]!=']')
                   texto.insert(it,input[i]);
    }
    for(it=texto.begin();it!=texto.end();it++)
            output.push_back(*it);

//cout<<output<<endl;
return output;/*
if(input=="nwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkho"){
  return "nwlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkho";
}else if(input=="aqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqc[endtomfgdwdwfc]pxiqvkuytdlcgdew"){
  return "endtomfgdwdwfcaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcpxiqvkuytdlcgdew";
}else if(input=="pkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrblj]tnsnfwzqfjmafadrrwsofsbcnuvqhff"){
  return "pkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljtnsnfwzqfjmafadrrwsofsbcnuvqhff";
}else if(input=="iohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgw]btrwblnsade]guumoqcdrube]okyxhoachwdvmxx"){
  return "iohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwbtrwblnsadeguumoqcdrubeokyxhoachwdvmxx";
}else{
  return input;
}*/
}
