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
		int Bridge(int sv,int parent,vector<int> ,vector <int> ,int time);
	
};

void Graph::addEdge(int x,int y){
	l[x].push_back(y);
	l[y].push_back(x);
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

int Graph::Bridge(int sv,int parent,vector<int> visited,vector<int> arrival,int time){
	    visited[sv]=1;
	    arrival[sv]=++time;
	    int dbe=arrival[sv]; //dbe is deepest back edge
	    for(int adj:l[sv]){
		    if(!visited[adj]){
			    dbe=min(dbe,Bridge(adj,sv,visited,arrival,time));
		     }
		     else if(adj!=parent){
		              dbe=min(dbe,arrival[adjg1.addEdge]);  
					                  
                         }
			 
	   }
	   if(dbe==arrival[sv] && parent!=-1){
	       cout<<parent<<","<<sv<<endl;
	       }

	       return dbe;
}

int main(){
	Graph g(6);
	g.addEdge(0,2);
        g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,4);
	g.addEdge(3,5);
	int v=6;
        vector<int> visited(v,0);
	vector<int> arrival(v);
	g.Bridge(0,-1,visited,arrival,0);
	
	return 0;
}
