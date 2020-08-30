#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>



using namespace std;

class Graph{
	int v;
	list<int > *l;
	
	public:
		Graph(int V){
			v=V;
			l=new list<int> [v];
		}

		void addEdge(int x,int y,bool );
		void print();
		void Bfs(int sv);
		void Dfs(int sv);
		void DfsHelper(int sv,bool visited[]);
		void DfsIterative(int sv);
};

void Graph::addEdge(int x,int y,bool d){
	l[x].push_back(y);
	if(d){
	    l[y].push_back(x);
	}
}

void Graph::print(){
	for(int i=0;i<v;i++){
		cout<<i<<"-->";
	//      for(auto it=l[i].begin();it!=l[i].end();it++){
	//		cout<<*it<<",";
	//	}
	        for(int nbr:l[i]){
			cout<<nbr<<",";
		}

		cout<<endl;
	}
}

void Graph::Bfs(int sv){
	vector<char> colour(v,'w');
	vector<int > level(v,0);
	queue<int>q;
	colour[sv]='g';
	level[sv]=0;
	q.push(sv);
	
	while(!q.empty()){
		int f=q.front();
		for(int adj:l[f]){
			if(colour[adj]=='w'){
				q.push(adj);
				level[adj]=level[f]+1;
				colour[adj]='g';
			}
		}
		colour[f]='b';
		cout<<f<<" ";
		q.pop();
	}
	cout<<endl;
	
//	for(int i=0;i<level.size();i++){
//		cout<<"vertex"<<i<<" at level"<<level[i];
//		cout<<endl;
//	}
}
void Graph::DfsHelper(int sv,bool visited[]){
	visited[sv]=true;
	cout<<sv<<" ";
	for(int nbr:l[sv]){
		if(!visited[nbr]){
			DfsHelper(nbr,visited);
		}
	}
}

void Graph::Dfs(int sv){
	bool *visited=new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	DfsHelper(sv,visited);
}

void Graph::DfsIterative(int sv){
	vector<bool> visited(v,false);
	stack<int> s;
	s.push(sv);

	while(!s.empty()){
		sv=s.top();
		s.pop();
		if(!visited[sv]){
			cout<<sv<<" ";
			visited[sv]=true;
		}

			for(int nbr:l[sv]){

			if(!visited[nbr]){
				s.push(nbr);			
			}		
			}
	}
	
		cout<<endl;
}

int main(){
	Graph g(4);
        g.addEdge(0, 1,false);
        g.addEdge(0, 2,false); 
        g.addEdge(1, 2,false); 
        g.addEdge(2, 0,false); 
        g.addEdge(2, 3,false); 
        g.addEdge(3, 3,false);
	g.print();

	g.Bfs(2);
//	g.Dfs(0);
	cout<<endl;

	g.DfsIterative(0);
	
	
	return 0;
}
