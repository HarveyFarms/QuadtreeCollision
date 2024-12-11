class Quad {
  public:
    Quad(int l, int r, int t, int b, Quad * p = nullptr)
      : left(l), right(r), top(t), bottom(b), parent(p) {}
    int left;
    int right;
    int top;
    int bottom;
    Quad * parent;
    Quad * children[4];
};
