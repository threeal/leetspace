char* triangleType(int* nums, int numsSize) {
  (void)numsSize;
  const int a = nums[0], b = nums[1], c = nums[2];
  if (a + b > c && a + c > b && b + c > a) {
    if (a == b) return b == c ? "equilateral" : "isosceles";
    return a == c || b == c ? "isosceles" : "scalene";
  }
  return "none";
}
