#include<iostream>
#include<list>
using namespace std;


class Graph{
int V;
list <int> *l;

public:
    Graph(int V){
        this->V=V;
        l=new list <int > [V];
    }

    void Add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }

    void PrintList(){
        for (int i=0;i<V;i++){
            cout<<i<<" -> ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    Graph g(4);
    g.Add_edge(1,3);
    g.Add_edge(1,2);
    g.Add_edge(2,3);
    g.Add_edge(0,3);

    g.PrintList();
    return 0;
}