const bool debug = true;
class Quad {
  public:
    Quad(int l, int r, int t, int b, int d = 0, Quad * p = nullptr)
      : left(l), right(r), top(t), bottom(b), depth(d), parent(p) {
        children[0] = nullptr;
        children[1] = nullptr;
        children[2] = nullptr;
        children[3] = nullptr;
      }
    ~Quad() {
    }
    void delete_children() {
      if (children[0] == nullptr)
        return;
      children[0]->delete_children();
      delete children[0];
      children[1]->delete_children();
      delete children[1];
      children[2]->delete_children();
      delete children[2];
      children[3]->delete_children();
      delete children[3];
    }
    void update() {
      if (children[0] == nullptr) {
        for (std::vector< Circle * >::iterator i = v.begin(); i != v.end(); ++i) {
          for (std::vector< Circle * >::iterator j = std::next(i); j != v.end(); ++j) {
              (*i)->handle_collision(**j);
          }
        }
      }
      else {
        children[0]->update();
        children[1]->update();
        children[2]->update();
        children[3]->update();
      }
    }
    bool intersects(const Quad * quad, const Circle& circle) {
      return !(circle.x + Circle::r < quad->left || 
          circle.x - Circle::r > quad->right || 
          circle.y + Circle::r < quad->top || 
          circle.y - Circle::r > quad->bottom);
    }
    void draw() {
      if (debug) {
        s_->put_line(left, top, right, top, DARKGRAY);
        s_->put_line(left, top, left, bottom, DARKGRAY);
        s_->put_line(right, top, right, bottom, DARKGRAY);
        s_->put_line(left, bottom, right, bottom, DARKGRAY);
      }
    }
    void build() {
      if (v.size() > 10 && depth < 5) {
        int mid_x = left + (right - left) / 2;
        int mid_y = top + (bottom - top) / 2;
        children[0] = new Quad(left, mid_x, top, mid_y, depth + 1, this);
        children[1] = new Quad(mid_x, right, top, mid_y, depth + 1, this);
        children[2] = new Quad(left, mid_x, mid_y, bottom, depth + 1, this);
        children[3] = new Quad(mid_x, right, mid_y, bottom, depth + 1, this);
        while (!v.empty()) {
          Circle * i = v.back(); v.pop_back();
          if (intersects(children[0], *i))
            children[0]->v.push_back(i); // Top-left
          if (intersects(children[1], *i))
            children[1]->v.push_back(i); // Top-left
          if (intersects(children[2], *i))
            children[2]->v.push_back(i); // Top-left
          if (intersects(children[3], *i))
            children[3]->v.push_back(i); // Top-left
        }
      }
      if (children[0] != nullptr) {
        children[0]->build();
        if (children[0] == nullptr)
          return;
        children[1]->build();
        children[2]->build();
        children[3]->build();
      }
    }
    int left;
    int right;
    int top;
    int bottom;
    int depth;
    Quad * parent;
    Quad * children[4];
    std::vector< Circle * > v;
    static Surface * s_;
    static void set_surface(Surface * s)
    {
      s_ = s;
    }
};
