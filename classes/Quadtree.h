class Quad {
  public:
    Quad(int l, int r, int t, int b, Quad * p = nullptr)
      : left(l), right(r), top(t), bottom(b), parent(p) {}
    void draw() {
      s_->put_line(left, top, right, top, GREEN);
      s_->put_line(left, top, left, bottom, GREEN);
      s_->put_line(right, top, right, bottom, GREEN);
      s_->put_line(left, bottom, right, bottom, GREEN);
    }
    int left;
    int right;
    int top;
    int bottom;
    Quad * parent;
    Quad * children[4];
    static Surface * s_;
    static void set_surface(Surface * s)
    {
      s_ = s;
    }
};
