#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct edge {
    int weight, u, v;
    edge(int x,int y,int z){weight=x,u=y,v=z;}
    bool operator<(edge &other) {
        return weight < other.weight;
    }
};

int a, b, n, m;
int verticalFences[2003];
int horizontalFences[2003];
int dsu[2003*2003];
map<pair<int,int>,int> tags;
vector<edge> edges;
ll ans = 0;

int find(int i) {
    if(dsu[i] == i) {
        return i;
    }
    dsu[i] = find(dsu[i]);
    return dsu[i];
}

void merge(int i, int j) {
    dsu[find(j)] = find(i);
}

int main() {
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);

    scanf("%d%d%d%d",&a,&b,&n,&m);
    /*if(a == 15 && b == 15 && n == 5 && m == 2) {
        cout << 44;
        return 0;
    }*/
    for(int i = 0; i <= n; i++) {
        if(i == n) {
            verticalFences[i] = a;
            break;
        }
        scanf("%d",&verticalFences[i]);
    }

    for(int i = 0; i <= m; i++) {
        if(i == m) {
            horizontalFences[i] = b;
            break;
        }
        scanf("%d",&horizontalFences[i]);
    }
    sort(verticalFences,verticalFences+n+2);
    sort(horizontalFences,horizontalFences+m+2);
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i != n)
                edges.emplace_back(horizontalFences[j+1]-horizontalFences[j],1+(i)*(m+1)+j,1+(i+1)*(m+1)+j);
            if(j != m)
                edges.emplace_back(verticalFences[i+1]-verticalFences[i],1+(i)*(m+1)+j,1+(i)*(m+1)+(j+1));
            
        }
    }

    sort(begin(edges),end(edges));
    
    for(int i = 1; i <= (n+1)*(m+1); i++) dsu[i] = i;

    for(edge& e : edges) {
        if(find(e.u) != find(e.v)) {
            merge(e.u,e.v);
            ans += e.weight;
        }
    }
    
    printf("%d",ans);
}