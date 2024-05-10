#ifndef COLLIDERCLASS_H
#define COLLIDERCLASS_H


class Collider {
private:
	int x;
	int y;
	int dim_x;
	int dim_y;
	bool show;
	bool active;

public:
	Collider(int, int, int, int);
	~Collider();
	void set_x(int);
	void set_y(int);
	void set_dim_x(int);
	void set_dim_y(int);

	int get_x();
	int get_y();
	int get_dim_x();
	int get_dim_y();

	void showCollider();

	bool CollingTo(Collider*);

};

#endif // !COLLIDERCLASS_H
