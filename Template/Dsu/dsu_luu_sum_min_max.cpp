void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    mn[v] = value[v];
    sum[v] = value[v];
    // value[v] là giá trị của phần tử thứ v
}

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        sum[a] += sum[b];
        mn[a] = min(mn[a], mn[b]);
    } 
}

int find_sum(int v) { // Trả về tổng của các phần tử trong tập hợp chứa v
    v = find_set(v);
    return sum[v];
}

int find_min(int v) { // Trả về giá trị bé nhất của các phần tử trong tập hợp chứa v
    v = find_set(v);
    return mn[v];
}