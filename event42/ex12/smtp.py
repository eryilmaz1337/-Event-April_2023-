import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage

# E-posta sunucusu ve bağlantı bilgileri
smtp_server = "smtp.yandex.com.tr"
smtp_port = 465 # Yandex için SMTP portu, SSL bağlantısı gerekiyor

# E-posta gönderen bilgileri
sender_email = "info@armoniraf.com"
sender_password = "hyuulbczqfopjnuy"

# E-posta alıcısı bilgileri
receiver_email = "149erdem@gmail.com"


# E-posta mesajı oluşturma
msg = MIMEMultipart()
msg['From'] = sender_email
msg['To'] = receiver_email
msg['Subject'] = "Deneme E-postası"

body = "Merhaba, bu bir deneme e-postasıdır."
msg.attach(MIMEText(body, 'plain'))

# E-posta ekleri
with open("./42.png", "rb") as f:
    img_data = f.read()
    image = MIMEImage(img_data, name="42.png")
    msg.attach(image)

# SMTP sunucusuna bağlanma ve e-posta gönderme
try:
    smtp_obj = smtplib.SMTP_SSL(smtp_server, smtp_port)
    smtp_obj.login(sender_email, sender_password)
    smtp_obj.sendmail(sender_email, receiver_email, msg.as_string())
    print("E-posta gönderildi!")
except Exception as e:
    print("Bir hata oluştu:", e)
finally:
    smtp_obj.quit()
