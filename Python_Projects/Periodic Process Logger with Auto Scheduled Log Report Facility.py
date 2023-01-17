import psutil
import smtplib, ssl
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders
from datetime import datetime
import schedule
import time


def processdisplay():

    fd=open("log.txt","a")
    now = datetime.now()
    dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
    dt="Date and Time : "
    fd.write(dt)
    fd.write(dt_string)
    fd.write('\n')
    fd.write('\n')
    for proc in psutil.process_iter():
        try:
            nam=proc.name()
            pi=proc.ppid()
            user=proc.username()
            fd.writelines([str(pi),"   ",nam,"   ",user])
            fd.write('\n')

        except(psutil.NoSuchProcess,psutil.AccessDenied,psutil.ZombieProcess):
            pass

    print("Enter email to send mail : ")
    receive = input()
    Mailing(receive)

def Mailing(receiver):
    port = 587  # For starttls
    smtp_server = "smtp.gmail.com"
    sender_email = "admankar2018@gmail.com"
    receiver_email = receiver
    password = "vpylzrgwccskhpbt"

    msg = MIMEMultipart()
    msg['Subject'] = "This is an Automate Email"
    body = "This mail is just for practise purpose"
    msg.attach(MIMEText(body, 'plain'))
    filename = "log.txt"
    attachment = open("C:/Users/91940/Desktop/Marvellous Python/log.txt", "rb")
    p = MIMEBase('application', 'octet-stream')
    p.set_payload((attachment).read())
    encoders.encode_base64(p)
    p.add_header('Content-Disposition', "attachment; filename= %s" % filename)
    msg.attach(p)
    text = msg.as_string()

    context = ssl.create_default_context()
    with smtplib.SMTP(smtp_server, port) as server:
        # server.ehlo() : email server to identify itself when connecting to another email server to start the process of sending an email.
        server.starttls(context=context)
        # server.ehlo()
        server.login(sender_email, password)
        server.sendmail(sender_email, receiver_email, text)


def main():
    print("Automation")
    print("current time is : ",datetime.now())
    schedule.every(1).minutes.do(processdisplay)
    while(True):
        schedule.run_pending()
        time.sleep(1)




if __name__=="__main__":
    main()