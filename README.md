# Hedge Trading

파생상품 가격 민감도(Greeks)를 계산하고, 바닐라 콜옵션을 예시로 델타 헤징을 구현하는 실습 노트북입니다. 몬테카를로 시뮬레이션과 유한차분법으로 델타를 계산한 뒤 두 방법을 비교하고, 시간에 따라 변하는 델타를 이용해 헤지 포트폴리오를 조정하는 과정을 다룹니다.

## 구성

- `4.Hedge Trading.ipynb`: 헤지 트레이딩 개념, 델타 헤징, Greeks 계산, MC/FDM 기반 델타 추정, 바닐라 콜옵션 델타 헤징 실습

## 주요 내용

- 헤지 트레이딩과 델타 헤징의 정의
- 델타, 감마, 세타 등 Greeks의 의미
- Monte Carlo Simulation을 이용한 델타 계산
- Finite Difference Method를 이용한 델타 계산
- MC와 FDM 결과 비교
- 바닐라 콜옵션의 동적 델타 헤징 구현

## 실행 환경

노트북은 Python 3 커널을 기준으로 작성되었습니다. 주요 패키지는 다음과 같습니다.

- `numpy`
- `pandas`
- `scipy`
- `matplotlib`

필요 패키지를 설치한 뒤 Jupyter Notebook 또는 JupyterLab에서 `4.Hedge Trading.ipynb`를 실행하면 됩니다.
