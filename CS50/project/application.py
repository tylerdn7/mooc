from flask import Flask, redirect, render_template, request, url_for

import helper
import os
import sys
import html
import os
import plotly
import socket
from helper import get_user_timeline
from nltk import TweetTokenizer
from twython import Twython
from twython import TwythonAuthError, TwythonError, TwythonRateLimitError

from analyzer import Analyzer
from termcolor import colored
from analyzer import Analyzer

app = Flask(__name__)
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    if request.method == "GET":
        p = db.execute("SELECT * FROM portfolio WHERE id = :id",id=session["user_id"])
        q = db.execute("SELECT cash FROM users WHERE id = :id",id=session["user_id"])
        #r = db.execute("SELECT price FROM portfolio WHERE id = :id",id=session["user_id"])

        return render_template("index.html",p=p,q=q[0]['cash'])

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "GET":
        return render_template("buy.html")
    else:
        p = db.execute("SELECT cash FROM users WHERE id = :id",id = session["user_id"])
        share = lookup(request.form.get("stock"))
        amnt = request.form.get("amount")

        if p[0]['cash'] >= share['price'] * float(amnt):
            db.execute("UPDATE users SET cash = cash - :buy WHERE id = :id",buy=share['price'] * float(amnt),id = session["user_id"])
            db.execute("INSERT INTO portfolio(id,symbol,amount,price,time) VALUES(:id,:symbol,:amount,:price,CURRENT_TIMESTAMP)",id=session["user_id"],symbol=share['symbol'],
            amount=amnt,price=share['price'] * float(amnt))
            db.execute("INSERT INTO history(id,symbol,amount,price,b_s,time) VALUES(:id,:symbol,:amount,:price,:b_s,CURRENT_TIMESTAMP)",id=session["user_id"],symbol=share['symbol'],
            amount=amnt,price=share['price'] * float(amnt),b_s=1)
            render_template("buy.html")
    return render_template("buy.html")
@app.route("/history")
@login_required
def history():
    """Show history of transactions."""
    if request.method == "GET":
        p = db.execute("SELECT * FROM history WHERE id = :id",id=session["user_id"])
        q = db.execute("SELECT cash FROM users WHERE id = :id",id=session["user_id"])
    return render_template("history.html",p=p,q=q[0]['cash'])

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        #quote = lookup("quote")
        #if quote:
        render_template("quote.html")
        username=request.form.get("quote")
        return render_template("quoted.html",quote=lookup(username))


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user."""
    if request.method == "GET":
        return render_template("register.html")
    else:
        if not request.form.get("username"):
            return apology("must provide username")

        elif not request.form.get("password"):
            return apology("must provide password")
        else:
            hash = pwd_context.hash(request.form.get("password"))
            result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)",username=request.form.get("username"),hash=hash)
            session["user_id"] = result
    return redirect(url_for("index"))

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    if request.method == "GET":
        p = db.execute("SELECT * FROM portfolio WHERE id = :id",id=session["user_id"])
        q = db.execute("SELECT cash FROM users WHERE id = :id",id=session["user_id"])
        #r = db.execute("SELECT price FROM portfolio WHERE id = :id",id=session["user_id"])
        return render_template("sell.html",p=p,q=q[0]['cash'])
    else:
        p = db.execute("SELECT * FROM portfolio WHERE id = :id",id=session["user_id"])
        q = db.execute("SELECT cash FROM users WHERE id = :id",id=session["user_id"])
        p1 = request.form.get("symbol")
        p2 = request.form.get("amnt")
        se = int(p2)

        for i in p:
            if i['symbol'] == p1.upper():
                ll = lookup(p1)
                ll = float(ll['price'])
                kom = int(i['amount'])
                tim = i['symbol']
        if kom > int(request.form.get("amnt")) and kom > 0:
            kim = db.execute("UPDATE portfolio SET amount = amount - :value WHERE id = :id", value = kom - int(request.form.get("amnt")),id=session["user_id"])
            dim = lookup(p1)
            dim = float(dim['price'])
            vim = db.execute("UPDATE users SET cash = cash + :value WHERE id = :id",value =int(request.form.get("amnt")) * dim,id=session["user_id"])
            db.execute("INSERT INTO history(id,symbol,amount,price,b_s,time) VALUES(:id,:symbol,:amount,:price,:b_s,CURRENT_TIMESTAMP)",id=session["user_id"],symbol=tim,
            amount=int(request.form.get("amnt")),price=se*ll,b_s=0)
            return render_template("index.html",p=p,q=q[0]['cash'])
        elif kom == int(request.form.get("amnt")) and kom > 0:
            kim = db.execute("DELETE FROM portfolio WHERE symbol=:symbol",symbol=tim)
            dim = lookup(p1)
            dim = float(dim['price'])
            vim = db.execute("UPDATE users SET cash = cash + :value WHERE id = :id",value =int(request.form.get("amnt")) * dim,id=session["user_id"])
            db.execute("INSERT INTO history(id,symbol,amount,price,b_s,time) VALUES(:id,:symbol,:amount,:price,:b_s,CURRENT_TIMESTAMP)",id=session["user_id"],symbol=tim,
            amount=int(request.form.get("amnt")),price=se*ll,b_s=0)
        return render_template("index.html",p=p,q=q[0]['cash'])
@app.route("/addcash", methods=["GET","POST"])
@login_required
def addcash():
    if request.method == "GET":
        render_template("addcash.html")
    else:
        db.execute("UPDATE users SET cash = cash + :cash WHERE id=:id",cash=float(request.form.get("amnt")),id=session["user_id"])
    return render_template("addcash.html")

@app.route("/indeex")
def indeex():
    return render_template("indeex.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")
    # get screen_name's tweets
    tweets = helper.get_user_timeline(screen_name)

    # TODO
    analyzer = Analyzer(positives, negatives)


    s = tweets
    s = str(s)
    # analyze word
    tw = TweetTokenizer()
    #print(tw.tokenize(s))
    p = tw.tokenize(s)
    score = analyzer.analyze2(p)


    positive = float(score[0])
    if score[1] < 0:
        score[1] = -score[1]
        negative = float(score[1])
    else:
        negative = float(score[1])
    neutral = score[2]

    # generate chart
    chart = helper.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
