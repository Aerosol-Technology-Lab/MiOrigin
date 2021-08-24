import socketserver
import json
import multiprocessing as mp
from flask import Flask, request
import time

HOST, PORT = 'localhost', 2000

app = Flask(__name__)

class MyTCPHandler(socketserver.BaseRequestHandler):

    def handle(self):
        self.data = self.request.recv(1024).strip()
        print('Data received:{}'.format(self.data))
        test_object = {
            'com': 'command'
        }

        try:
            obj = json.loads(self.data)
        except:
            return

        if 'com' not in obj:
            return

        # if obj['com'] == 'register'
        
        self.request.sendall(json.dumps(test_object).encode())

@app.route('/')
def index():
    return '<p>Hello, World!</p>'

@app.route('/api/miorigin')
def api_miorigin():
    rate = request.args.get('rate')
    time = request.args.get('time')

    if rate is None:
        return 'FAIL'
    
    if time is None:
        time = float('inf')

    print(rate)
    print(time)
    return 'Good!'

def flaskserver():
        app.run()

def main():
    # start flask server
    p = mp.Process(target=flaskserver, daemon=True)
    p.start()

    
    with socketserver.TCPServer((HOST, PORT), MyTCPHandler) as server:
        server.serve_forever()

if '__main__' in __name__:
    main()
