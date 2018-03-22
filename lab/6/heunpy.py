print 'X	yexact	yheun     %errorheun    yeuler	  %erroreuler'
x_i = raw_input()
x_f = raw_input()
h = raw_input()
y_i = raw_input()
x_f = float(x_f) + 0.5
k = (float(x_f)-float(x_i))/float(h)
x = 0.0
soln = [[0 for i in range(int(k))] for y in range(5)]
i = 0
for i in range(int(k)):
  y = -1*0.5*x*x*x*x + 4*x*x*x - 10*x*x + 8.5*x+1     #exact
  soln[0][i] = y
  soln[1][0] = float(y_i)                             #heun's
  soln[2][0] = 0.0
  if i > 0:
    x_temp = x - float(h)
    dy1 = -1*2*x*x*x + 12*x*x - 20*x + 8.5
    dy2 = -1*2*x_temp*x_temp*x_temp + 12*x_temp*x_temp - 20*x_temp + 8.5
    dy = (dy1 + dy2)/2
    soln[1][i] = soln[1][i-1] + float(h)*dy
    soln[2][i] = abs(((soln[0][i] - soln[1][i])/soln[0][i])*100)
  soln[3][0] = float(y_i)                            #euler's
  soln[4][0] = 0.0
  if i > 0:
    x_temp = x - float(h)
    dy = -1*2*x_temp*x_temp*x_temp + 12*x_temp*x_temp - 20*x_temp + 8.5
    soln[3][i] = soln[3][i-1] + float(h)*dy
    soln[4][i] = abs(((soln[0][i] - soln[3][i])/soln[0][i])*100)
  print  '%.4f	%.4f	%.4f	  %.4f        %.4f    %.4f' % (x, soln[0][i], soln[1][i], soln[2][i], soln[3][i], soln[4][i])
  x = x + float(h)

