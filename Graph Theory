void tarjan(int u){
    dfs_num[u]=dfs_low[u]=(int)compnum++;
    path.push(u);
    inpath[u]=1;
    for(size_t i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(dfs_num[v]==unvisited){
            tarjan(v);
        }
        if(inpath[v])dfs_low[u]=dfs_low[u]<dfs_low[v]?dfs_low[u]:dfs_low[v];
    }
    if(dfs_num[u]==dfs_low[u]){
        int s;
        while(!path.empty()){
            s=path.top();path.pop();inpath[s]=0;
            printf("%s%s",inttostring[s].c_str(),s==u?"\n":", ");
            if(s==u) break;
        }
    }
}
//Finding TarjanSCC

inline bool bfs(int u){
    queue<int> q;q.push(u);vy.assign(Y,0);
    while(!q.empty()){
        int w=q.front();q.pop();
        for(int c:adjx[w])
            if(!vy[c]){
                vy[c]=1,py[c]=w;
                if(my[c]==-1){
                    while(1){
                        int stay=mx[w];
                        mx[w]=c,my[c]=w;
                        if(stay==-1)return 1;
                        c=stay; w=py[c];
                    }
                }
                else q.push(my[c]);
            }
    }
    return false;
}
//bipartite matching with BFS

void dfs(){
    if(solution.size()==adjlist.size()){for(size_t j=0;j<adjlist.size();j++)printf("%c",solution[j]);printf("\n");}
    else{
        for(size_t j=0;j<adjlist.size();j++){
            if(degminus[j]==0){
                solution.push_back(prob[j]);
                degminus[j]--;
                for(size_t t=0;t<adjlist[j].size();t++) degminus[adjlist[j][t]]--;
                dfs();
                for(size_t t=0;t<adjlist[j].size();t++) degminus[adjlist[j][t]]++;
                degminus[j]++;
                solution.pop_back();
            }
        }
    }
}
//Topological Sorting with backtracting

int greedy(){
    int a=0;
    for(int i=0;i<adj.size();i++){
        if(mapp[i]==-1)
        for(int j=0;j<10;j++){
            if(adj[i][j] && mcpu[j]==-1){mcpu[j]=i;mapp[i]=j;a++;break;}
        }
    }
    return a;
}
bool Aug(int i){
    if(!vapp[i]){
        vapp[i]=1;
    for(size_t j=0;j<10;j++){
        if(adj[i][j])
        if(mcpu[j]==-1||Aug(mcpu[j]))
        {mcpu[j]=i;mapp[i]=j;return true;}
    }
    }
    return false;
}
//greedy matching and finding augmenting path\

void favb(int i,int dfsroot){
    dfs_num[i]=dfs_low[i]=dfsnumber++;
    for(size_t h=0;h<ADJ[i].size();h++){
        int v=ADJ[i][h];
        if(dfs_num[v]==unvisited){
            parent[v]=i;
            if(i==dfsroot)rootchildren++;
            favb(v,dfsroot);
            if(dfs_low[v]>=dfs_num[i] && i!=dfsroot)V[i]=1;
            dfs_low[i]=dfs_low[i]<dfs_low[v]?dfs_low[i]:dfs_low[v];
        }else if(parent[i]!=v){
            dfs_low[i]=dfs_low[i]<dfs_num[v]?dfs_low[i]:dfs_num[v];
        }
    }
}
//finding accumulation vertice
inline int lca(int i,int j,int root){
    static int t=1;
    for(t++;;swap(i,j)){
        if(i!=j&&i==root) continue;
        if(vis[i]==t) {vis[i]=t;return i;}
        vis[i]=t;
        i=Flower[pa[match[i]]];//go to stem if it has
    }
}//

inline void flower(int i,int j,int l){
    while(Flower[i]!=l){
        pa[i]=j;
        if(S[j=match[i]]==1) qpush(j);
        Flower[i]=Flower[j]=l,i=pa[j];
    }
}

inline bool bfs(int i){
    memset(S, -1, V*sizeof(int));
    while(!q.empty())q.pop();qpush(i);
    for(int a=0;a<V;a++) Flower[a]=a;
    
    while(!q.empty()){
        int v=qpop();
        for(int u:adj[v]){//v must be even
            if(S[u]==-1){//the edge must be non-match
                pa[u]=v,S[u]=1;
                if(match[u]==-1){//v is unsaturated
                    while(1){
                        int stay=match[v];
                        match[v]=u,match[u]=v;
                        if(stay==-1) return true;
                        u=stay;v=pa[u];
                    }
                }
                qpush(match[u]);//alternating
            }
            if(!S[u] && Flower[u]!=Flower[v]){
                int l=lca(u, v,i);
                flower(u,v,l); flower(v,u,l);
            }
        }
    }
    return false;
}
//finding maximum matching
