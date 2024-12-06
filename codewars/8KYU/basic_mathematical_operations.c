int basic_op(char op, int value1, int value2) {
  switch(op) {
      case '+':
        return value1 + value2;
      case '-':
        return value1 - value2;
      case '*':
        return value1 * value2;
      case '/':
        return value1 / value2;
  }
  return 0;
}
// self explanatory
