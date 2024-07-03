# MD 만들기


주별로 푼 문제들을 정리하고 확인하기 편하게 하기 위함

```
.
├── README.md
├── archive
│   └── week1.md
├── internal
│   ├── README.md
│   ├── main.go
│   ├── md.go
│   └── problem.go
└── week1
    ├── BOJ11057
    │   ├── seho.java
    │   └── seorim.java
    └── README.md
    ...
```
  

다음과 같은 디렉토리 구조에서
해당 week 디렉토리 안에  
아래의 양식으로 README.md 파일을 만들어 준다


> # WEEK1
> 
> ### BOJ_11057: 오르막 수
> 
> |이름|풀이 링크|
> |--|--|
> |seho| [link](BOJ11057/seho.java)
> |seorim| [link](BOJ11057/seorim.java)
> ---



### 사용법   
루트 디렉터리에서 `go run internal/*` 
