import turtle

def tree(branchLen,t):
    if branchLen > 10:
        t.forward(branchLen)
        t.left(20)
        tree(branchLen-15,t)
        t.right(40)
        tree(branchLen-15,t)
        t.left(20)
        t.backward(branchLen)

def main():
    t = turtle.Turtle()
    # t.ht()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    t.color("green")
    tree(100,t)
    turtle.done()

main()