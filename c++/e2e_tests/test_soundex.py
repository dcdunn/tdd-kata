import os
import pytest
from hamcrest import assert_that, equal_to
from subprocess import Popen, PIPE

PATH_TO_MODULE = os.path.dirname(__file__)
EXE = os.path.join(PATH_TO_MODULE, "../msvc/x64/Debug/app.exe")

@pytest.fixture
def process():
    yield Popen(EXE, stdin=PIPE, stdout=PIPE)

def test_process_returns_success(process):
    ret_code = process.wait()
    assert_that(ret_code, equal_to(0))

def test_outputs_result(process):
    stdoutdata = process.communicate()[0]
    assert_that(stdoutdata, equal_to("Hello, world!"))