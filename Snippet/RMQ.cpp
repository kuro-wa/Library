// 1. Segment Tree
// 1-1. Range Min Query
using S = int;
const S IE = 1001001001;
S op(S a, S b) { return min(a, b);}
S e() { return IE;}
  vector<S> vec(n, S(0));
  segtree<S, op, e> d(vec);
//
// 1-2. Range Max Query
using S = int;
const S IE = -1001001001;
S op(S a, S b) { return max(a, b);}
S e() { return IE;}
  vector<S> vec(n, S(0));
  segtree<S, op, e> d(vec);
//

// 2. Lazy SegTree
// 2-1. Range Add Query and Range Min Query
using S = int;
using F = int;
const S IE = 1001001001;
S op(S a, S b) { return min(a, b);}
S e() { return IE;}
S mapping(F f, S s) { return f+s;}
F composition(F f, F g) { return f+g;}
F id() { return F(0);}
using lseg = lazy_segtree<S, op, e, F, mapping, composition, id>;
  vector<S> vec(n, S(0));
  lseg d(vec);
//
// 2-2. Range Add Query and Range Max Query
using S = int;
using F = int;
const S IE = -1001001001;
S op(S a, S b) { return max(a, b);}
S e() { return IE;}
S mapping(F f, S s) { return f+s;}
F composition(F f, F g) { return f+g;}
F id() { return F(0);}
using lseg = lazy_segtree<S, op, e, F, mapping, composition, id>;
  vector<S> vec(n, S(0));
  lseg d(vec);
//