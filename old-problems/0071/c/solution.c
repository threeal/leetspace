struct range_t {
  int l;
  int r;
};

char* simplifyPath(char* path) {
  struct range_t dirs[1500];
  int dirsSize = 0;

  for (int l = 1; path[l] != 0; ++l) {
    if (path[l] != '/') {
      int r = l + 1;
      while (path[r] != 0 && path[r] != '/') ++r;

      if (r - l == 2 && path[l] == '.' && path[l + 1] == '.') {
        if (dirsSize > 0) --dirsSize;
      } else if (r - l != 1 || path[l] != '.') {
        dirs[dirsSize].l = l;
        dirs[dirsSize].r = r;
        ++dirsSize;
      }

      l = r - 1;
    }
  }

  if (dirsSize == 0) return "/";

  int n = 0;
  for (int i = 0; i < dirsSize; ++i) {
    path[n++] = '/';
    for (int l = dirs[i].l; l < dirs[i].r; ++l) {
      path[n++] = path[l];
    }
  }
  path[n] = 0;

  return path;
}
