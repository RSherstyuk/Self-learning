# Makefile для uv-проекта
SHELL := /bin/sh


# ---------- Переменные ----------
PY := uv                  # команда-обёртка: uv run ... или просто uv add ...
PY_RUN := $(PY) run
PY_ADD := $(PY) add
PY_SYNC := $(PY) sync
PY_VENV := $(PY) venv
PY_VERSION := $(PY) --version

# Тесты/линтеры/форматтеры
PYTEST := pytest
RUFF := ruff
BLACK := black
ISORT := isort

# Опции по умолчанию (можно переопределять при вызове: make TEST_OPTS="-k fast")
TEST_OPTS ?=
RUFF_OPTS ?=
BLACK_OPTS ?=
ISORT_OPTS ?=

# ---------- Фиктивные цели ----------
.PHONY: help init install-uv add run test lint fmt clean sync venv

# ---------- Помощь ----------
help:
	@printf "\nUsage:\n"
	@printf "  make init         # установить uv (если нужно) и базовые dev-зависимости\n"
	@printf "  make add PKG=...  # добавить зависимость (пример: make add PKG=requests)\n"
	@printf "  make run ARGS=\"<args>\"   # запустить команду через uv (пример: make run ARGS=\"python main.py\")\n"
	@printf "  make test         # запустить pytest\n"
	@printf "  make lint         # запустить ruff\n"
	@printf "  make fmt          # запустить black + isort\n"
	@printf "  make sync         # синхронизировать зависимости (uv sync)\n"
	@printf "  make clean        # удалить артефакты сборки\n\n"

# ---------- Проверка: установлен ли uv ----------
check-uv:
	@command -v uv >/dev/null 2>&1 || { printf "uv не найден. Установите его: https://astral.sh/uv\n"; exit 1; }
	@printf "uv: " && $(PY_VERSION) >/dev/null 2>&1 || true

# ---------- Инициализация проекта ----------
# Устанавливаем dev-зависимости, если нужно. Не создаёт pyproject, предполагает, что проект уже инициализирован.
init: check-uv
	@printf "Инициализация проекта (проверка uv и установка рекомендуемых dev-пакетов)...\n"
	# пример: добавить pytest, ruff, black как dev
	@$(PY_ADD) --dev pytest || true
	@$(PY_ADD) --dev ruff || true
	@$(PY_ADD) --dev black || true
	@$(PY_ADD) --dev isort || true
	@printf "Готово. Проверьте pyproject.toml и uv.lock.\n"

# ---------- Добавить зависимость ----------
# Используй: make add PKG=requests
add:
ifdef PKG
	@printf "Добавляю зависимость: $(PKG)\n"
	@$(PY_ADD) $(PKG)
else
	@printf "Ошибка: укажи пакет: make add PKG=<имя_пакета>\n"
	@exit 1
endif

# ---------- Запуск команд внутри uv ----------
# Пример: make run ARGS="uvicorn app:app --reload" или make run ARGS="python -m my_package"
run:
ifdef ARGS
	@printf "Запуск: $(ARGS)\n"
	@$(PY_RUN) $(ARGS)
else
	@printf "Ошибка: укажи ARGS, например: make run ARGS=\"python -m my_package\"\n"
	@exit 1
endif

# ---------- Тесты ----------
test: check-uv
	@printf "Запуск pytest $(TEST_OPTS)\n"
	@$(PY_RUN) $(PYTEST) $(TEST_OPTS)

# ---------- Линтер ----------
lint: check-uv
	@printf "Запуск ruff $(RUFF_OPTS)\n"
	@$(PY_RUN) $(RUFF) $(RUFF_OPTS) .

# ---------- Форматирование ----------
fmt: check-uv
	@printf "Запуск isort, black\n"
	@$(PY_RUN) $(ISORT) $(ISORT_OPTS) src tests || true
	@$(PY_RUN) $(BLACK) $(BLACK_OPTS) src tests || true

# ---------- Синхронизация зависимостей (обновление lock) ----------
sync: check-uv
	@printf "uv sync\n"
	@$(PY_SYNC)

# ---------- Утилиты виртуальной среды (если нужно) ----------
venv: check-uv
	@printf "uv venv (подсказки):\n"
	@$(PY_VENV) path || true

# ---------- Очистка (build-artifacts) ----------
clean:
	@printf "Чистим временные файлы...\n"
	@rm -rf .pytest_cache
	@rm -rf build dist *.egg-info
	@find . -name "__pycache__" -type d -exec rm -rf {} +
	@find . -name "*.pyc" -type f -delete
	@printf "Готово.\n"

