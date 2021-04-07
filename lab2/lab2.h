/* graph : draws a quadratic equation given frame size and zoom level  */
void graph(double a, double b, double c, double step, int xleft, int xright,
int ybottom, int ytop);

/* draw_row : draws a line of asterisks and spaces */
void draw_row(double a, double b, double c, double step, int xleft, int xright,
int ybottom, int ytop, int x, int y);

/* draw_whole : iterates over the rows and draws the entire graph */
void draw_whole(double a, double b, double c, double step, int xleft, int xright,
int ybottom, int ytop, int x, int y);

/* graph : checks whether the coordinate frame is legal and calls draw_whole */ 
void graph(double a, double b, double c, double step, int xleft, int xright,
int ybottom, int ytop);

/* main : calls the graph function */ 
int main();