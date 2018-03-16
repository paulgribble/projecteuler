
struct node {
	double key_value;
	struct node *left;
	struct node *right;
};

void destroy_tree(struct node *leaf);
void insert(double key, struct node **leaf); // only adds if doesn't exist yet
struct node *search(double key, struct node *leaf);
void print_tree(struct node *leaf);
int count_tree(struct node *leaf);
