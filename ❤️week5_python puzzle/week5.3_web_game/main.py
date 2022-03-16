from flask import Flask,jsonify,render_template,redirect,url_for

app = Flask(__name__)
#解决中文乱码的问题，将json 数据内的中文正常显示
app.config['JSON_AS_ASCII'] = False




@app.route('/')
def index():
    return render_template('homepage.html')



@app.route('/usb')
def admin():
    # return redirect(url_for("user",name="Admin!"))
    return render_template('page2.html')

@app.route('/calculator')
def calcul():
    return render_template('page3.html')

@app.route('/mushroom')
def room():
    return render_template('final_page.html')

@app.route('/jump')
def nextpage():
    return render_template('homepage.html')

if __name__ == '__main__':
    app.run(debug=True)
