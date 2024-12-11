/* Complete function saleHotdogs/SaleHotDogs/sale_hotdogs, function accepts 1 parameter:n, n is the number of hotdogs a customer will buy, different numbers have different prices (refer to the following table), return how much money will the customer spend to buy that number of hotdogs.

number of hotdogs	price per unit (cents)
n < 5			100
n >= 5 and n < 10	95
n >= 10			90
You can use if..else or ternary operator to complete it. */
unsigned short sale_hotdogs(unsigned short n) {
  return (n < 5) ? (n * 100) : (n >= 5 && n < 10) ? (n * 95) : (n * 90);
}
