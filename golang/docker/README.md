
## run container
```
docker run -d --name=hoge alpine tail -f /dev/null 
```

## build image
```
docker build -t piyo . 
```

## delete images
```
docker ps -a | awk '{print $1}' | tail -n +2 | xargs docker rm
```
