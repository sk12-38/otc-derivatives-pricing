# OTC Derivatives Pricing

장외 파생상품 가격결정(pricing) 관련 스터디 자료를 GitHub 업로드용으로 정리한 저장소입니다.  
주요 Jupyter Notebook과 보조 C++ 소스 코드를 보기 쉽도록 재구성했습니다.

## 이번 정리 내용

- 노트북 파일명을 정리해 `notebooks/` 아래에 순서대로 배치했습니다.
- FDM, MCS 관련 C++ 예제 코드는 `src/` 아래로 분리했습니다.
- 변동성 곡면 노트북에서 사용하는 데이터 파일을 함께 포함했습니다.
- 원본 강의 자료 중 GitHub 업로드에 불필요한 대용량 보조 파일은 제외했습니다.

## 저장소 구성

- `notebooks/`
  - `01_pricing_interest_rate.ipynb`
  - `02_monte_carlo_simulation.ipynb`
  - `03_finite_difference_method.ipynb`
  - `04_hedge_trading.ipynb`
  - `05_american_option_lsmc_convertible_bond.ipynb`
  - `06_volatility_surface.ipynb`
  - `07_bootstrapping_ir_derivatives.ipynb`
  - `08_cb_pricing.ipynb`
  - `09_credit_derivatives.ipynb`
  - `S&P500_option.xlsx`
- `src/fdm/`
  - 유한차분법(FDM) 관련 예제 소스 코드
- `src/mcs/`
  - 몬테카를로 시뮬레이션 관련 예제 소스 코드와 메모

## 다루는 주제

- 파생상품 가격결정 기초와 이자율
- 몬테카를로 시뮬레이션
- 유한차분법을 이용한 옵션 가격결정
- 헤지 트레이딩과 Greeks
- 아메리칸 옵션, LSMC, 전환사채(Convertible Bond)
- 변동성 곡면(Volatility Surface)
- 부트스트래핑과 이자율 파생상품
- 전환사채 가격결정
- 신용파생상품 가격결정

## 실행 환경

주요 패키지는 아래와 같습니다.

- `numpy`
- `pandas`
- `scipy`
- `matplotlib`
- `jupyter`

필요 패키지는 다음 명령으로 설치할 수 있습니다.

```bash
pip install -r requirements.txt
```

## 참고 사항

- 변동성 곡면 노트북에서 사용하는 데이터 파일은 `notebooks/S&P500_option.xlsx`에 포함되어 있습니다.
- 원본 PDF, zip 파일, notebook checkpoint, 실행 파일(`.exe`) 등은 GitHub 업로드 대상에서 제외했습니다.
- 실습 흐름은 기초 pricing → Monte Carlo → FDM → 변동성 곡면 → IR/Credit derivatives 순서로 따라가면 자연스럽습니다.
