import turtle
import math

PROGNAME = 'Tree'

def drawTree(distance, angle, pen, height, now):

	if now != 0:

		if now != height:
			if (now + 1) == height:
				pen.pencolor('#129e03')
			else:
				pen.pencolor('#964B00')
			pen.setheading(90 + angle)

			curpos = pen.pos()
			curang = pen.heading()
			dist = distance * 0.8

			A = draw(dist, angle + 20, pen)
			pen.goto(curpos[0], curpos[1])
			pen.setheading(90 + curang)
			B = draw(dist, angle - 20, pen)

			pen.goto(A[0], A[1])
			drawTree(dist, angle + 20, pen, height, now + 1)
			pen.goto(B[0], B[1])
			drawTree(dist, angle - 20, pen, height, now + 1)

		else:
			pen.pencolor('#129e03')
			pen.setheading(90 + angle)

			curpos = pen.pos()
			curang = pen.heading()
			dist = distance * 0.8

			A = draw(dist, angle + 20, pen)
			pen.goto(curpos[0], curpos[1])
			pen.setheading(90 + curang)
			B = draw(dist, angle - 20, pen)
			return

	else:

		pen.pencolor('#964B00')
		pen.setheading(90 + angle)
		draw(distance, angle, pen)
		drawTree(distance, angle, pen, height, now + 1)

def draw(distance, angle, pen):
	pen.setheading(90 + angle)
	pen.down()
	pen.forward(distance)
	pen.up()
	return pen.pos()

def main():
	myPen = turtle.Turtle()
	myPen.ht()
	myPen.speed(10)
	myPen.setheading(90)
	myPen.up()
	myPen.goto(0, -300)

	height = 8

	drawTree(distance = 100.0, angle = 0, pen = myPen, height = height, now = 0)
	turtle.done()


main()