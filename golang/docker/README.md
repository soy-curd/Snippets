

```
docker run -it -d -p 8080:80 --name=hoge tcp
docker exec -it hoge sh
```

としてコンテナを起動した後、
コンテナの中でシェルを起動します。

まずは、コンテナのネットワークの状態を見てみましょう。

```
hostname
```

`b24e2511fa6f` これは、Dockerが生成したホスト名になります。また、

```
ip addr show
```
でipを確認すると、eth0に172.17.0.2が割り当てられていることがわかります。

```
tcpdump
```
を実行します。


その状態で、ホストのブラウザから`localhost:8080`にアクセスすると、


```
14:27:54.931554 IP 172.17.0.1.54756 > f28f8f2283f7.80: Flags [S], seq 3360679968, win 29200, options [mss 1460,sackOK,TS val 7144624 ecr 0,nop,wscale 7], length 0
14:27:54.931620 IP f28f8f2283f7.80 > 172.17.0.1.54756: Flags [R.], seq 0, ack 3360679969, win 0, length 0
```

というログが取れます。

Flags [S] がSYN（コネクション確立要求）、[R.]がRST（コネクション切断要求）+ ACKという意味なので、接続に失敗していることがわかります。

それでは、ここで簡易的なhttpサーバーを立ててみます。
```
(echo "HTTP/1.0 200 Ok"; echo; echo "Hello") | busybox nc -l -p 80
```

もう一度ホストのブラウザから`localhost:8080`にアクセスしてみましょう。

```
13:50:50.864066 IP 172.17.0.1.54796 > b24e2511fa6f.80: Flags [S], seq 1030088291, win 29200, options [mss 1460,sackOK,TS val 7812768 ecr 0,nop,wscale 7], length 0
13:50:50.867269 IP b24e2511fa6f.80 > 172.17.0.1.54796: Flags [S.], seq 3467863790, ack 1030088292, win 28960, options [mss 1460,sackOK,TS val 7812769 ecr 7812768,nop,wscale 7], length 0
13:50:50.867558 IP 172.17.0.1.54796 > b24e2511fa6f.80: Flags [.], ack 1, win 229, options [nop,nop,TS val 7812769 ecr 7812769], length 0
13:50:50.881627 IP b24e2511fa6f.80 > 172.17.0.1.54796: Flags [P.], seq 1:24, ack 1, win 227, options [nop,nop,TS val 7812770 ecr 7812769], length 23: HTTP: HTTP/1.0 200 Ok

```
PがPUSH（受信したデータをすぐに上位のアプリケーションに渡す）ですので、3way ハンドシェイクの後に、データが送られていることがわかります。




## 参考
+ http://blog.livedoor.jp/sonots/archives/34703829.html
+ https://qiita.com/keikmobile/items/93cf6dc5b95019c6a442


## build image
```
docker build -t tcp . 
```

## run container
```
docker run -d --name=hoge alpine tail -f /dev/null 
```

## delete images
```
docker ps -a | awk '{print $1}' | tail -n +2 | xargs docker rm
```
