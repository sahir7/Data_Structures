#include<iostream>
#include<vector>
#include<list>


using namespace std;

class Graph{
        list<int> *l;
        int v;
        public:
                Graph(int V){
                        v=V;
                        l=new list<int>[v];
                }

                void addEdge(int x,int y);
                void print();
		bool Acyclic(int sv,vector<int> ,vector <int> );

};

void Graph::addEdge(int x,int y){
        l[x].push_back(y);
}

void Graph::print(){
        for(int i=0;i<v;i++){
                cout<<i<<"->";
                for (int adj:l[i]){
                        cout<<adj<<" ";
                }
                cout<<endl;
        }
}

bool Graph::Acyclic(int sv,vector<int> visited,vector<int> restack){
	visited[sv]=1;
	restack[sv]=1;
	
	for(int adj:l[sv]){
		if(!visited[adj] && Acyclic(adj,visited,restack) ){
			return true;
		}
		else if(restack[adj]==1)
	        {
			return true;
		
		}
	  }
	restack[sv]=0;
	return false;


}


int main(){
        Graph g(6);
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,3);
        g.addEdge(3,4);
        g.addEdge(4,5);
        int v=6;
        vector<int> visited(v,0);
        vector<int> restack(v,0);

        if(g.Acyclic(0,visited,restack)){
		cout<<"cycle is found";
	}
	else{
		cout<<"not found"<<endl;
	}
	return 0;
}
