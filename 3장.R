#1
#(a)
par (mfrow = c(1,1))
x<- seq(-1,1,length = 100)
y<- x^2 
#(b)
plot(x,y,pch = 8, xlim = c(-1,1), ylim = c(-1,1)) 
#(c)
plot(x,x^2,type = 'l',col='red')

#2
x<-seq(0,5,0.1)
y_1<-x
y_2<- x^2
y_3<- log(x)
y_4<- sqrt(x)
#(a)
par (mfrow = c(1,1))
plot(x,y_1)
plot(x,y_2) 
plot(x,y_3)
plot(x,y_4)
#(b)
y_all<- cbind(y_1,y_2,y_3,y_4)       
matplot(x,y_all,type = 'l')        
#(c)
plot(x,y_1, type = 'p')
lines(x,y_2,type='l')              
lines(x,y_3, type='b')
lines(x,y_4, type = 'b')

#3
par (mfrow = c(1,1))
x <- seq(-pi,pi,0.01)
plot(x,sin(x), type='l', col="red")
lines(x,cos(x), col="blue")
y <- tan(x)
thres <- 1                    
y[y>thres] = NA
y[y<-thres] = NA
lines(x,y,col="green")


#4
install.packages("UsingR")
library(UsingR)
data(primes)
histogram(primes, col = 'blue')

#5
#(a)
#ë¬¸ì œ?— ì£¼ì–´ì§? ê³µì‹?´?š©?•˜?Š” ë°©ã…‚
x<- seq(-3,3,0.1)
f_x<-(1/sqrt(2*pi)*exp(1))^(-1/2*(x^2))
plot(x,f_x,type = 'l')
#?Œ¨?‚¤ì§€?´?š©?•˜?Š” ë°©ë²• 'dnorm'?•¨?ˆ˜ê°€ ?‘œì¤€? •ê·œë¶„?¬ ê³„ì‚° ?•¨?ˆ˜?´
x = seq(-3,3, 0.1)     
y = dnorm(x)
plot(x, y, type='l')
#(b)
f_x<- exp(-abs(x))
plot(x,f_x, type = 'l')

#6
lambda<- c(0.5,1,2)
x<- seq(0,5,0.01)
f_x<- lambda*exp(1)^(-lambda*x)
matplot(x,f_x,type='l',col='red')

#7
x<-1:6
p_j=c(1/6,1/6,1/6,1/6,1/6,1/6)
plot(x,p_j)



#8
#(a)
par (mfrow = c(1,1))
x<- seq(-2,2,length=30) 
y<- seq(-3,3,length=30)
f=function(x,y){x^2 + y^2 + x*(y-3)}
z<-outer(x,y,FUN = f)
persp(x,y,z,col = 'red')

#(b)
x<- seq(-5,5,length = 50)
y<- seq(-5,5,length =50)
f = function(x,y){1-exp(-1*(1/(x^2+y^2)))}
z<-outer(x,y,FUN = f)
persp(x,y,z, col = 'blue')
#(c)
x<- seq(0,16, length = 50)
y<- seq(0,16, length = 50)
f = function(x,y){x*sin(y)}
z<-outer(x,y, f)
persp(x,y,z, col = 'green')


##########

plot(x,y, type = 'p')
lines(x,y2,type='l')                #linesë¥? ?´?š©?•˜ë©? ê·¸ëž˜?”„ ?œ„?— ì¶”ê?€!
lines(x,ylog, type='b')
lines(x,ysq, type = 'b')

head(USArrests)



#9
#(a)
splom(crime)

#(b)
install.packages("aplpack")
library(aplpack)
crime_f<-crime[,c(3:10)]
View(crime_f)
faces (crime_f, face.type = 0, main = "crime face")
faces (crime_f, face.type = 1, main = "crime face")
#(c)
install.packages("reshape")
library(reshape)
stars(crime_f)
#(d)
mean(crime$arson)
sd(crime$arson) 


#10
data("OrchardSprays")
#(a)
xyplot(decrease~colpos|treatment, data=OrchardSprays)       
#(b)
mean(OrchardSprays$decrease)
var(OrchardSprays$decrease) 
#(c)
boxplot(OrchardSprays$decrease)                           
#(d)
xyplot(colpos~decrease, data = OrchardSprays, sub = 'OrchardSprays')
.
#11
x<- seq(0,2*pi,length = 100)
z1<- sin(3*x) + sin(4*x)
z2<- sin(3*x) + sin(6*x)
z3<- sin(5*x) + sin(8*x)
z4<- sin(4*x) + sin(7*x)

plot(x,z1, type = 'l', col = 'red')
lines(x,z2, col = 'green')   
lines(x,z3, col = 'blue')
lines(x,z4, col = 'yellow')


#12

stretch_a<-c(46,54,48,50,44,42,52)
distance_a<-c(183,217,189,208,178,150,249)
stretch_b<-c(25,45,35,40,55,60)
distance_b<- c(71,196,127,187,249,291)
s1<- cbind(stretch_a, distance_a)
s2<- cbind(stretch_b,distance_b)

plot(s1,type = 'p',pch = 'a',col = 'blue')
lines(s2,type='p',pch='b',col = 'red')



# graph 4
plot(stretch_a, distance_a, xlim = c(0,300))
text(x=bodywt, y = brainwt, labels = animal, adj=0)  


a = data.frame(stretch=c(46, 54, 48, 50, 44, 42, 52), 
               distance= c(183, 217, 189, 208, 178, 150, 249))
b = data.frame(stretch=c(25, 45, 35, 40, 55, 60),
               distance=c(71, 196, 127, 187, 249, 291))

plot(a, type='p', pch='a')
lines(b, type='p', pch='b')

ss=read.csv(file="C:/Users/User/Desktop/band.csv")
attach(ss)
win.graph()
plot(stretch,distance,type='n')
text(x=stretch,y=distance, labels=class)

#---------------------------------
#4.9
b<- c(1.5, 2.2, 0.9, 1.3, 2.0, 1.2, 2.5, 2.7, 1.8, 2.3)
#(a)
hist(b)
#(b)
qqnorm(b)
qqline(b)
#(c)
shapiro.test(b)
#(d)
mean(b)
var(b)
sd(b)


#---------------------------
#5.8
tv<- c(5.7, 6.7, 6.8, 7.9, 10.6, 11.3, 9.8, 8.4, 8.3, 9.5,
       6.7, 6.9, 9.8, 8.8, 12.1, 10.2, 9.5, 9.4, 9.3, 5.9)
#(a)
mtv<- mean(tv)
mtv
#(b)
ci<- c((mtv-qt(0.975,19)*sd(tv)/sqrt(20)),(mtv+qt(0.975,19)*sd(tv)/sqrt(20)))
ci
#(c)
var(TV)
sd(TV)
range(TV)
#(d)
boxplot(tv)
#(e)
x<- seq(5,13,0.01) 
lines(x, dnorm(x,mean(tv),sd(tv)))
hist(tv)



#5.9
p<- c(20870, 39400, 65000, 45000, 35890, 29000, 56770,
        23000, 38550, 59800, 39880, 56780, 35220, 48990)
#(a)
mean(p)
#(b)
ci<- c((mean(p)-qt(0.975,13)*sd(p)/sqrt(14)),(mean(p)+qt(0.975,13)*sd(p)/sqrt(14)))
ci
#(c)
var(p) 
sd(p) 
range(p)
#(d)
boxplot(p)
#(e)
hist(p,probability = T)
lines(density(p))

#5.10
w<- c(120,80)
80/200
120/200

#5.11
n<- c(5.6, 7.8, 6.5, 7.2, 6.9, 7.3, 5.8, 7.5, 8.2, 7.8)
#(a)
mn<- mean(n)
mn
#(b)
ci<- c((mn-qnorm(0.975)*sd(n)/sqrt(10)),(mn+qnorm(0.975)*sd(n)/sqrt(10)))
ci
#(c)
var(n)
sd(n)
range(n)
#(d)
boxplot(n)
