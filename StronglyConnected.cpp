#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
	int v;
	list<int> *l;
	public:
		Graph(int v){
		      this->v=v;
			l=new list<int>[v];
		}
		
		~Graph(){
			delete [] l;
		}
		
		void addEdge(int x,int y);
		
		bool IsSC(int sv);
		void Dfshelper(int,bool visited[]);
		
		Graph getTranspose();


};

void Graph::addEdge(int x,int y){
	l[x].push_back(y);
}


void Graph::Dfshelper(int sv,bool visited[]){
	visited[sv]=true;
	for(int adj:l[sv]){
		if(!visited[adj]){
			Dfshelper(adj,visited);
		}
	}
}

Graph Graph::getTranspose(){
	Graph g(v);
	for(int i=0;i<v;i++){
		for(int adj:l[i]){
			g.l[adj].push_back(i);
		}

	}
	return g;
}




bool Graph::IsSC(int sv){
	bool visited[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

        Dfshelper(sv,visited);

	for(int i=0;i<v;i++){
		if(visited[i]==false){
			return false;
		}
	}

	Graph gr=getTranspose();
	
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	gr.Dfshelper(sv,visited);

	for(int i=0;i<v;i++){
		if(visited[i]==false){
			return false;
		}
	}

	return true;
}

	




int main(){
	Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    g1.IsSC(0)? cout << "Yes\n" : cout << "No\n";

    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.IsSC(0)? cout << "Yes\n" : cout << "No\n"; 
	return 0;
}
