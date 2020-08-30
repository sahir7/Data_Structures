#include<iostream>
#include<list>
#include<stack>

using namespace std;

class Graph{
	int v;
	list<int> *l;
	public:
		Graph(int v){
			this->v=v;
			l=new list<int>[v];
		}
		
		void addEdge(int x,int y);

		void Sort();
		void Dfs(int sv,bool visited[],stack<int> &s);

};

void Graph::addEdge(int x,int y){
	l[x].push_back(y);
}


void Graph::Dfs(int sv,bool visited[],stack<int> &s){
	visited[sv]=true;
	for(int adj:l[sv]){
		if(!visited[adj]){
		Dfs(adj,visited,s);
		}
	}
           s.push(sv);
}
void Graph::Sort(){
	bool visited[v];
	stack<int> s;
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	for(int i=0;i<v;i++){
		if(!visited[i]){
			Dfs(i,visited,s);
		}
	}
	


	while(s.empty()==false){

		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.Sort();
	return 0;
}
