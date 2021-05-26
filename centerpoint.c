struct point {
  float x;
  float y;
  float z;
};

void centerPoint(struct point** points, int n, struct point* center) {
  int i = 0;
  center->x = 0;
  center->y = 0;
  center->z = 0;

  // Iterate over all x, y, and z points in the array and create a running sum.
  for (i = 0; i < n; i++) {
    struct point *temp = *(points + i);
    center->x += temp->x;
    center->y += temp->y;
    center->z += temp->z;
  }

  // Compute the average of all x, y, and z point values. This is the center.
  center->x = center / n;
  center->y = center / n;
  center->z = center / n;

}

int main(void) {
  struct point center;
  struct point* points[100];
  setPoints(points, 100); // Dynamically allocates the points and initializes the points
  centerPoint(points, 100, &center);
  printf("center point is (%f, %f, %f)\n", center.x, center.y, center.z);
  return 0;
}
