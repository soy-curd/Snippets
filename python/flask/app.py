from flask import Flask, send_from_directory, make_response, jsonify

from lib.crossdomain import crossdomain

app = Flask(__name__)


@app.route('/')
@crossdomain(origin='*')
def show_entries():
    return make_response(jsonify({"hoge": "fuga", "foo": 12345}))


@app.route('/static/<path:path>')
def send_js(path):
    return send_from_directory('js', path)


@app.route('/static/<path:path>')
def send_css(path):
    return send_from_directory('css', path)


if __name__ == "__main__":
    app.run(port=8082, debug=True)
