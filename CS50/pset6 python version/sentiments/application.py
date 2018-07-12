from flask import Flask, redirect, render_template, request, url_for

import helpers
import os
import sys
import html
import os
import plotly
import socket
from helpers import get_user_timeline
from nltk import TweetTokenizer
from twython import Twython
from twython import TwythonAuthError, TwythonError, TwythonRateLimitError

from analyzer import Analyzer
from termcolor import colored
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))
    positives = os.path.join(sys.path[0], "positive-words.txt")
    negatives = os.path.join(sys.path[0], "negative-words.txt")
    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name)

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
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
