# 🎞OTT Controller project🎞

기능 구현 목록
* 마우스 이동 및 클릭 - o
* 볼륨 조절 - o
* Mute - o
* 영상 이동 버튼 - o
* 재생/일시정지 버튼 - o
* 블루투스 기능
* 배터리 연결 및 충전 단자
* 브라우저 단축키 버튼
* 영상 속도 조절 슬라이더
* 전원 버튼

## 🕹하드웨어
* 아두이노 LEONARDO -> esp32로 변경될 수 있음
    * esp32로 변경시 3.3V 전압 고려

## 🎧프로젝트 개요
### 📅프로젝트 소개와 문제정의
누구나 쉽게 사용할 수 있고, 사용하지 않고 책상 위에 올려놓기만 하더라도 데스크테리어 용품으로 사용할 수 있는 제품을 생각하고 시작하게 되었습니다.

밖에 나와있는 시간보다 집에서 보내는 시간이 많았습니다! 밥을 먹으면서, 친구가 놀러와서 책상 앞에서 컴퓨터로 OTT를 보내는 시간이 정말 많은데 정작 키보드로 사용하는 키는 얼마 없구 자리만 많이 차지해서 불편함을 느꼈습니다. 아예 키보드를 책상에서 치워버리고 🎞OTT나 🕹youtube만을 위한 제품이 있으면 어떨까!?하며 제 취향의 제품을 만들고 있습니다.

### 📊시장조사
22년 통계 자료를 기준으로 OTT 서비스 이용률이 72%를 넘었습니다.(자료: 이상원 경희대학교 교수) 연령별 OTT 이용률 통계를 보더라도 10대~20대는 최근 3년간 90% 이상을 차지했고 22년 기준 20대의 OTT 이용률은 약96%로 집계되었습니다. 이는 한 명의 사용자가 1개 이상의 OTT를 사용해 나온 것으로 보입니다. 40대 이용자는 20년에는 약 74%를 차지했었지만 22년에는 87%까지 성장하였습니다. 전자기기에 익숙한 고연령대의 사람들이 늘어남에 따라 점차 OTT에 노출되는 정도가 커질 것이라 생각했습니다.

OTT 시청 기기는 📱스마트폰이 약 90%로 압도적으로 높습니다. 하지만 20년부터 조금씩 비중이 줄어들며 다른 기기들의 점유율이 높아지기 시작했습니다. 처음에는 편의성을 위해 휴대하기 편한 스마트폰의 점유율이 높았지만 사용자들이 좀 더 넓은 화면의 기기를 원한다 분석했습니다.

하나 더 참고한 자료는 1인 가구 추이입니다. 매년 꾸준히 1인 가구가 늘어나고 있고, 21년에는 약 716만명의 1인 가구가 집계되었습니다. 주소 이전이 안되는 생활형 숙박 시설등을 고려하면 이것보다 많은 수의 1인 가구가 있을 것이라 생각합니다. 20대 대학생들이나 사회 초년생들은 컴퓨터와 TV를 동시에 구매하는 것에는 무리가 있다 생각하였습니다. 코로나 이후 요새는 노트북이 없는 학생은 찾기가 어렵습니다. 프로젝트는 노트북과 컴퓨터를 마치 TV처럼 OTT 기계로 사용할 수 있도록 도와주는 🎮컨트롤러에 대한 개발입니다.

### 🖱기존 리모컨
크게 3가지 문제점을 생각했습니다.
- 복잡하고 많은 버튼 -> UI 문제
- 오래된 디자인 -> 디자인 문제
- 부피가 크고 환경에 영향을 받는 IR 방식 통신 -> 기능적 문제

