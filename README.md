# OTC Derivatives Pricing Study Notes

This repository reorganizes the derivatives study materials into a GitHub-friendly layout focused on pricing notebooks and supporting source code.

## Structure

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
  - finite-difference example source files
- `src/mcs/`
  - Monte Carlo example source files and notes

## Topics

- Pricing basics and interest-rate foundations
- Monte Carlo simulation for derivatives pricing
- Finite difference method for option pricing
- Hedge trading and Greeks
- American option pricing, LSMC, and convertible bonds
- Volatility surface construction
- Bootstrapping and interest-rate derivatives
- Convertible bond pricing
- Credit derivatives pricing

## Environment

Install the main Python packages with:

```bash
pip install -r requirements.txt
```

The notebooks mainly use:

- `numpy`
- `pandas`
- `scipy`
- `matplotlib`
- `jupyter`

## Notes

- The spreadsheet used by the volatility-surface notebook is included as `notebooks/S&P500_option.xlsx`.
- Large course assets such as the original PDF, zip archives, notebook checkpoints, and compiled binaries were intentionally left out of this repo layout.
