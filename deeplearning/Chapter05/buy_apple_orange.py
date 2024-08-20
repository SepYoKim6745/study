from Layer_navie import *

apple = 100
apple_num = 2

orange = 150
orange_num = 3

tax = 1.1

mul_buy_apple = MulLayer()
mul_buy_orange = MulLayer()
add_apple_orange = AddLayer()
tax_apple_orange = MulLayer()

#순전파
total_apple = mul_buy_apple.forward(apple, apple_num)
total_orange = mul_buy_orange.forward(orange, orange_num)

all_price = add_apple_orange.forward(total_apple, total_orange)

ret = tax_apple_orange.forward(all_price, tax)

print(ret)

#역전파
dprice = 1
dall_price, dtax = tax_apple_orange.backward(dprice)
dtotal_apple, dtotal_orange = add_apple_orange.backward(dall_price)
dapple, dapple_num = mul_buy_apple.backward(dtotal_apple)
dorange, dorange_num = mul_buy_orange.backward(dtotal_orange)

print(dapple, dapple_num, dorange, dorange_num, dtax)



