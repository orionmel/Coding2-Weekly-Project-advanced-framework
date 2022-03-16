from bs4 import BeautifulSoup
import requests
from csv import writer

url = "https://www.pararius.com/apartments/nederland?ac=1"
page = requests.get(url)

#访问html的文档
soup = BeautifulSoup(page.content,'html.parser')

#找到每个section叫listing-search-item__title的名字的类
lists = soup.find_all('section',class_= "listing-search-item")

#'w'表示write，
with open('housing.csv','w',encoding='utf8',newline='')as f:
    thewriter = writer(f)
    header = ['Title','Location','Price','Area']
    thewriter.writerow(header)

    for list in lists :
        title = list.find('a',class_="listing-search-item__link listing-search-item__link--title").text.replace('\n','')
        location = list.find('div', class_="listing-search-item__location").text.replace('\n','')
        price = list.find('div', class_="listing-search-item__price").text.replace('\n','')
        area = list.find('li', class_="illustrated-features__item illustrated-features__item--surface-area").text.replace('\n','')
        info=[title,location,price,area]
        thewriter.writerow(info)


